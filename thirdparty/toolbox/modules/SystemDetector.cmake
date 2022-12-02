include(CheckIncludeFileCXX)

check_include_file_cxx("iosfwd" HAVE_IOSFWD_H)

check_include_file_cxx("regex" HAVE_REGEX_H)
if (HAVE_REGEX_H)
	set(HAVE_STD_REGEX 1)
endif ()

check_include_file_cxx("exception" HAVE_EXCEPTION_H)
check_include_file_cxx("termios.h" HAVE_TERMIOS_H)
check_include_file_cxx("unistd.h" HAVE_UNISTD_H)