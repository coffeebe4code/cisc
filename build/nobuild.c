#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h"

#define CFLAGS "-Werror",

void first_run() {
  MKDIRS("target");
  MKDIRS("lib");
  MKDIRS("obj");
  MKDIRS("bin");
  MKDIRS("static");
  MKDIRS("deps");
}

void build_feature(const char *dir) {
  FOREACH_FILE_IN_DIR(file, PATH(".", dir), { INFO("   %s", file); });
}

int main(int argc, char **argv) {
  chdir("build");

  INFO("Building...");
  MKDIRS("target", "lib", "obj", "bin", "static");
  INFO("...Finished");
  return 0;
}
