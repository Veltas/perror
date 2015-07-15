#include <errno.h>
#include <getopt.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

void print_help(const char *argv0)
{
  printf("Usage: %s { ERRNO | --help }\n", argv0);
}

int main(int argc, char *argv[])
{
  struct option lopts[] = {{.name = "help", .val = 'h'}, {0}};
  
  /* Process any options given */
  int opt;
  while (
    (opt = getopt_long(argc, argv, "h", lopts, NULL)) != -1
  )
  {
    switch (opt)
    {
      case 'h':
	print_help(argc > 0 ? argv[0] : "perror");
	return 0;
      case '?':
	return EINVAL;
    }
  }
  
  /* Otherwise we expect just the one argument: the error number */
  if (argc != 2)
  {
    fputs("Expected just one argument, see -h / --help\n", stderr);
    return argc > 2 ? E2BIG : EINVAL;
  }
  
  int input_number;
  if (sscanf(argv[1], "%i", &input_number) != 1)
  {
    fputs("Expected integer argument, see -h / --help\n", stderr);
    return EINVAL;
  }
  
  /* And the whole point was this line */
  puts(strerror(input_number));
  
  return 0;
}
