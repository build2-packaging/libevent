./: {*/ -build/ -upstream/}                    \
    doc{README.md PACKAGE-README.md}           \
    doc{ChangeLog ChangeLog-2.0 ChangeLog-1.4} \
    legal{LICENSE} manifest

# Don't install tests.
#
tests/: install = false
