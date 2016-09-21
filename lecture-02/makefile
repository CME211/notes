LECDIR := $(abspath $(PWD))
LECHOME := $(abspath $(LECDIR)/..)

LECFILES := \
  0-interacting-with-python \
  1-values-variables-types \
  2-strings \
  3-numbers

NOTEBOOKS := $(LECFILES:=.ipynb)
PDFS := $(LECFILES:=.pdf)

all: $(NOTEBOOKS) $(PDFS)

include $(LECHOME)/defaults.mk
