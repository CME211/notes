CME211_PKG := $(LECHOME)/cme211-pkg.tex

PANDOC := pandoc
PANDOC_FLAGS := -H $(CME211_PKG)

%.ipynb : %.md
	notedown --match python $< > $@
	jupyter nbconvert --to notebook --execute --allow-errors --inplace $@

%.tex : %.md $(CME211_PKG)
	$(PANDOC) $(PANDOC_FLAGS) -o $@ $<

%.pdf : %.md $(CME211_PKG)
	$(PANDOC) $(PANDOC_FLAGS) -o $@ $<

.PHONY : clean-ipynb
clean-ipynb :
	$(RM) *.ipynb

.PHONY : clean-pdf
clean-pdf :
	$(RM) *.pdf

# for debugging
print-% : ; @echo $* = $($*)
