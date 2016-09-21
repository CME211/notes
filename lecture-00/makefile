LECDIR := $(abspath $(PWD))
LECHOME := $(abspath $(LECDIR)/..)

LECFILES := $(wildcard *.md)
NOTEBOOKS := $(LECFILES:.md=.ipynb)
PDFS := $(LECFILES:.md=.pdf)

all: $(PDFS)

include $(LECHOME)/defaults.mk
