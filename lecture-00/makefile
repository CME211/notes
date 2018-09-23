LECDIR := $(abspath $(PWD))
LECHOME := $(abspath $(LECDIR)/..)

LECFILES := $(wildcard *.md)
NOTEBOOKS := $(LECFILES:.md=.ipynb)
PDFS := $(LECFILES:.md=.pdf)

all: $(PDFS) 04-interacting-with-python.ipynb 05-values-variables-types.ipynb

include $(LECHOME)/defaults.mk
