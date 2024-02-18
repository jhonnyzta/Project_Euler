from setuptools import setup, Extension

module = Extension('mymod', 
                   sources=['./src/mymod.c', './src/mylib.c'],
                   extra_compile_args=['-O3'],)

setup(name='mymod',
      version='1.0',
      description="Find the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'",
      ext_modules=[module])
