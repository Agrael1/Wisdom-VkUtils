
find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format)
if( CLANG_FORMAT_EXECUTABLE )
	# get the clang-format version string
	execute_process( COMMAND ${CLANG_FORMAT_EXECUTABLE} "--version" OUTPUT_VARIABLE clangFormatVersion )
	# filter out the actual version
	string( REGEX MATCH [0123456789.]+ clangFormatVersion "${clangFormatVersion}" )

	message( STATUS " Found clang-format version <" ${clangFormatVersion} ">." )
else()
	message( WARNING " Could not find clang-format. Generated files will not be nicely formatted." )
endif()