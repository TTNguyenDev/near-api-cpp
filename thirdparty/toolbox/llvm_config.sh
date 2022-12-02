#!/bin/bash

## osx does not have ldconfig
if [[ "${CXX}" == *"clang++" ]] && [ ! -f /etc/ld.so.conf.d/llvm.conf ];
then
	clang_bin_dir=$(clang++ --version | grep InstalledDir | awk -F ": " '{print $NF}')
	llvmcfg_libdir=$(${clang_bin_dir}/llvm-config --libdir)

	echo ${llvmcfg_libdir} | sudo tee /etc/ld.so.conf.d/llvm.conf > /dev/null
	sudo ldconfig
	echo "Added llvm lib dir to ldconfig:"
	echo ${llvmcfg_libdir}
	echo ""

	#write for source'ing
	echo "#!/bin/sh" > build/env.sh
	echo "export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${llvmcfg_libdir}" >> build/env.sh
else
	#write empty env for complete sourcing
	echo "#!/bin/sh" > build/env.sh
fi