LECDIR := $(abspath $(PWD))
LECHOME := $(abspath $(LECDIR)/..)

LECFILES := $(wildcard *.md)
PDFS := $(LECFILES:.md=.pdf)

all: $(PDFS)

include $(LECHOME)/defaults.mk
