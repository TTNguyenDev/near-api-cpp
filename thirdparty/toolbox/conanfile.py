import os

from conans import ConanFile, CMake, tools


def get_version():
    with open(os.path.join(os.path.dirname(__file__), 'version.info'), 'r') as f:
        content = f.read()
        try:
            content = content.decode()
        except AttributeError:
            pass
        return content.strip()


class ToolboxConan(ConanFile):
    name = "toolbox"
    version = get_version()
    license = "MIT"
    author = "Eduard Maximovich edward.vstock@gmail.com"
    url = "https://github.com/edwardstock/toolbox"
    description = "Lightweight everyday C++ helpers"
    topics = ("cpp-helpers", "helpers")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {
        "shared": False
    }
    generators = "cmake"
    exports = "version.info"
    exports_sources = (
        "cfg/*",
        "modules/*",
        "options.cmake",
        "include/*",
        "tests/*",
        "src/*",
        "CMakeLists.txt",
        "conanfile.py",
        "LICENSE",
        "README.md"
    )
    build_requires = (
        "gtest/1.10.0"
    )

    def source(self):
        if "CONAN_LOCAL" not in os.environ:
            git = tools.Git(folder="toolbox")
            git.clone("https://github.com/edwardstock/toolbox.git", "master")

    def configure(self):
        if self.settings.compiler == "Visual Studio":
            del self.settings.compiler.runtime

        if self.settings.compiler == "gcc" and float(self.settings.compiler.version.value) < 6:
            self.requires.add("boost/1.76.0")
            print("WARN: adding boost to requirements")

    def build(self):
        cmake = CMake(self)
        opts = {
            'CMAKE_BUILD_TYPE': self.settings.build_type,
            'ENABLE_SHARED': "Off",
        }

        if self.options.shared:
            opts['ENABLE_SHARED'] = "On"

        cmake.configure(defs=opts)
        cmake.build(target="toolbox")

    def package(self):
        self.copy("*", dst="include", src="include", keep_path=True)
        dir_types = ['bin', 'lib', 'Debug', 'Release', 'RelWithDebInfo', 'MinSizeRel']
        file_types = ['lib', 'dll', 'dll.a', 'a', 'so', 'exp', 'pdb', 'ilk', 'dylib']

        for dirname in dir_types:
            for ftype in file_types:
                self.copy("*." + ftype, src=dirname, dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["toolbox"]

    def test(self):
        cmake = CMake(self)
        cmake.configure([], {'ENABLE_TEST': 'On'})
        cmake.build([], None, "toolbox-test")
        self.run("bin/toolbox-test")
