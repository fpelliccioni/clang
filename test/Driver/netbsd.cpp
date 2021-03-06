// RUN: %clangxx -no-canonical-prefixes -target x86_64--netbsd \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=X86_64 %s
// RUN: %clangxx -no-canonical-prefixes -target x86_64--netbsd7.0.0 \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=X86_64-7 %s
// RUN: %clangxx -no-canonical-prefixes -target x86_64--netbsd6.0.0 \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=X86_64-6 %s
// RUN: %clangxx -no-canonical-prefixes -target aarch64--netbsd \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=AARCH64 %s
// RUN: %clangxx -no-canonical-prefixes -target aarch64--netbsd7.0.0 \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=AARCH64-7 %s
// RUN: %clangxx -no-canonical-prefixes -target arm64--netbsd \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=ARM64 %s
// RUN: %clangxx -no-canonical-prefixes -target arm64--netbsd7.0.0 \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=ARM64-7 %s
// RUN: %clangxx -no-canonical-prefixes -target sparc--netbsd \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=SPARC %s
// RUN: %clangxx -no-canonical-prefixes -target sparc64--netbsd \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=SPARC64 %s

// RUN: %clangxx -no-canonical-prefixes -target x86_64--netbsd -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-X86_64 %s
// RUN: %clangxx -no-canonical-prefixes -target x86_64--netbsd7.0.0 -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-X86_64-7 %s
// RUN: %clangxx -no-canonical-prefixes -target x86_64--netbsd6.0.0 -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-X86_64-6 %s
// RUN: %clangxx -no-canonical-prefixes -target aarch64--netbsd -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-AARCH64 %s
// RUN: %clangxx -no-canonical-prefixes -target aarch64--netbsd7.0.0 -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-AARCH64-7 %s
// RUN: %clangxx -no-canonical-prefixes -target arm64--netbsd -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-ARM64 %s
// RUN: %clangxx -no-canonical-prefixes -target arm64--netbsd7.0.0 -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-ARM64-7 %s
// RUN: %clangxx -no-canonical-prefixes -target sparc--netbsd -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-SPARC %s
// RUN: %clangxx -no-canonical-prefixes -target sparc64--netbsd -static \
// RUN: --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
// RUN: | FileCheck -check-prefix=S-SPARC64 %s

// X86_64: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd"
// X86_64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// X86_64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// X86_64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc++"
// X86_64: "-lm" "-lc" "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// X86_64-7: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd7.0.0"
// X86_64-7: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// X86_64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// X86_64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc++"
// X86_64-7: "-lm" "-lc" "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// X86_64-6: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd6.0.0"
// X86_64-6: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// X86_64-6: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// X86_64-6: "-lm" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
// X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// AARCH64: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd"
// AARCH64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// AARCH64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// AARCH64: "-lm" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
// AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// AARCH64-7: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd7.0.0"
// AARCH64-7: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// AARCH64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// AARCH64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// AARCH64-7: "-lm" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
// AARCH64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// ARM64: clang{{.*}}" "-cc1" "-triple" "arm64--netbsd"
// ARM64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// ARM64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// ARM64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// ARM64: "-lm" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
// ARM64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// ARM64-7: clang{{.*}}" "-cc1" "-triple" "arm64--netbsd7.0.0"
// ARM64-7: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// ARM64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// ARM64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// ARM64-7: "-lm" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
// ARM64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// SPARC: clang{{.*}}" "-cc1" "-triple" "sparc--netbsd"
// SPARC: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// SPARC: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
// SPARC: "{{.*}}/usr/lib{{/|\\\\}}sparc{{/|\\\\}}crti.o"
// SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// SPARC: "-lm" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
// SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// SPARC64: clang{{.*}}" "-cc1" "-triple" "sparc64--netbsd"
// SPARC64: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/libexec/ld.elf_so"
// SPARC64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// SPARC64: "-lm" "-lc" "-lgcc" "--as-needed" "-lgcc_s" "--no-as-needed"
// SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-X86_64: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd"
// S-X86_64: ld{{.*}}" "-Bstatic"
// S-X86_64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-X86_64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc++"
// S-X86_64: "-lm" "-lc" "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-X86_64-7: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd7.0.0"
// S-X86_64-7: ld{{.*}}" "-Bstatic"
// S-X86_64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-X86_64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lc++"
// S-X86_64-7: "-lm" "-lc" "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-X86_64-6: clang{{.*}}" "-cc1" "-triple" "x86_64--netbsd6.0.0"
// S-X86_64-6: ld{{.*}}" "-Bstatic"
// S-X86_64-6: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// S-X86_64-6: "-lm" "-lc" "-lgcc_eh" "-lc" "-lgcc"
// S-X86_64-6: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-AARCH64: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd"
// S-AARCH64: ld{{.*}}" "-Bstatic"
// S-AARCH64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// S-AARCH64: "-lm" "-lc" "-lgcc_eh" "-lc" "-lgcc"
// S-AARCH64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-AARCH64-7: clang{{.*}}" "-cc1" "-triple" "aarch64--netbsd7.0.0"
// S-AARCH64-7: ld{{.*}}" "-Bstatic"
// S-AARCH64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-AARCH64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// S-AARCH64-7: "-lm" "-lc" "-lgcc_eh" "-lc" "-lgcc"
// S-AARCH64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-ARM64: clang{{.*}}" "-cc1" "-triple" "arm64--netbsd"
// S-ARM64: ld{{.*}}" "-Bstatic"
// S-ARM64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-ARM64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// S-ARM64: "-lm" "-lc" "-lgcc_eh" "-lc" "-lgcc"
// S-ARM64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-ARM64-7: clang{{.*}}" "-cc1" "-triple" "arm64--netbsd7.0.0"
// S-ARM64-7: ld{{.*}}" "-Bstatic"
// S-ARM64-7: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-ARM64-7: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// S-ARM64-7: "-lm" "-lc" "-lgcc_eh" "-lc" "-lgcc"
// S-ARM64-7: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-SPARC: clang{{.*}}" "-cc1" "-triple" "sparc--netbsd"
// S-SPARC: ld{{.*}}" "-Bstatic"
// S-SPARC: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o"
// S-SPARC: "{{.*}}/usr/lib{{/|\\\\}}sparc{{/|\\\\}}crti.o"
// S-SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// S-SPARC: "-lm" "-lc" "-lgcc_eh" "-lc" "-lgcc"
// S-SPARC: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"

// S-SPARC64: clang{{.*}}" "-cc1" "-triple" "sparc64--netbsd"
// S-SPARC64: ld{{.*}}" "-Bstatic"
// S-SPARC64: "-o" "a.out" "{{.*}}/usr/lib{{/|\\\\}}crt0.o" "{{.*}}/usr/lib{{/|\\\\}}crti.o"
// S-SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtbegin.o" "{{.*}}.o" "-lstdc++"
// S-SPARC64: "-lm" "-lc" "-lgcc_eh" "-lc" "-lgcc"
// S-SPARC64: "{{.*}}/usr/lib{{/|\\\\}}crtend.o" "{{.*}}/usr/lib{{/|\\\\}}crtn.o"
