#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void is_elf(unsigned char *elf_ptr);
void print_magic(unsigned char *elf_ptr);
void print_class(unsigned char *elf_ptr);
void print_data(unsigned char *elf_ptr);
void print_version(unsigned char *elf_ptr);
void print_abi(unsigned char *elf_ptr);
void print_osabi(unsigned char *elf_ptr);
void print_type(unsigned int elf_type, unsigned char *elf_ptr);
void print_entry(unsigned long int e_entry, unsigned char *elf_ptr);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @elf_ptr: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void is_elf(unsigned char *elf_ptr)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (elf_ptr[index] != 127 &&
			elf_ptr[index] != 'E' &&
			elf_ptr[index] != 'L' &&
			elf_ptr[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @elf_ptr: pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *elf_ptr)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", elf_ptr[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @elf_ptr: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *elf_ptr)
{
	printf(" Class: ");

	switch (elf_ptr[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ptr[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF header.
 * @elf_ptr: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *elf_ptr)
{
	printf(" Data: ");

	switch (elf_ptr[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ptr[EI_CLASS]);
	}
}

/**
 *  * print_version - Prints the version of an ELF header.
 *   * @elf_ptr: A pointer to an array containing the ELF version.
 *    */
void print_version(unsigned char *elf_ptr)
{
	printf(" Version: %d",
		   elf_ptr[EI_VERSION]);

	switch (elf_ptr[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @elf_ptr: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *elf_ptr)
{
	printf(" OS/ABI: ");

	switch (elf_ptr[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ptr[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @elf_ptr: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *elf_ptr)
{
	printf(" ABI Version: %d\n",
		   elf_ptr[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf_ptr: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int elf_type, unsigned char *elf_ptr)
{
	if (elf_ptr[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf(" Type: ");

	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @elf_ptr: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *elf_ptr)
{
	printf(" Entry point address: ");

	if (elf_ptr[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (elf_ptr[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	is_elf(header->elf_ptr);
	printf("ELF Header:\n");
	print_magic(header->elf_ptr);
	print_class(header->elf_ptr);
	print_data(header->elf_ptr);
	print_version(header->elf_ptr);
	print_osabi(header->elf_ptr);
	print_abi(header->elf_ptr);
	print_type(header->elf_type, header->elf_ptr);
	print_entry(header->e_entry, header->elf_ptr);

	free(header);
	close_elf(o);
	return (0);
}

