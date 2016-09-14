%.ipynb : %.md
	notedown --match python $< > $@

%.nbconvert.ipynb : %.ipynb
	jupyter nbconvert --to notebook --execute --allow-errors $<

%.pdf : %.nbconvert.ipynb
	jupyter nbconvert --to pdf $< --output $(basename $@)

.PHONY: clean-ipynb
clean-ipynb:
	$(RM) *.ipynb

.PHONY: clean-pdf
clean-pdf:
	$(RM) *.pdf

# for debugging
print-%  : ; @echo $* = $($*)
