from distutils.core import setup, Extension


if __name__ == "__main__":
    memcpy_module = Extension('memcopy', sources=['memcopy.c'])
    fputs_module = Extension('wtf', sources=['fputs.c'])
    def main():
        setup(
            name='My demo modules',
            version='1.0',
            description='Demo packages',
            ext_modules=[memcpy_module, fputs_module]
        )
    main()

