LECDIR := $(abspath $(PWD))
LECHOME := $(abspath $(LECDIR)/..)

LECFILES := $(wildcard *.md)
NOTEBOOKS := $(LECFILES:.md=.ipynb)
PDFS := $(LECFILES:.md=.pdf)

all: $(NOTEBOOKS) $(PDFS)

include $(LECHOME)/defaults.mk
