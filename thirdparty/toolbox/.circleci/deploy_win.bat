@echo off
set CONAN_LOCAL=1

for /f %%i in ('type ..\version.info') do set VERS=%%i

@rem default config
conan create . edwardstock/latest -s build_type=Debug --build=missing
conan create . edwardstock/latest -s build_type=Debug -s compiler.runtime=MDd --build=missing
conan create . edwardstock/latest -s build_type=Release --build=missing

@rem dll
conan create . edwardstock/latest -s build_type=Debug --build=missing -o shared=True
conan create . edwardstock/latest -s build_type=Release --build=missing -o shared=True

@rem
@rem conan upload toolbox/%VERS%@edwardstock/latest --all -r=edwardstock