%.ipynb : %.md
	notedown --match python $< > $@

%.nbconvert.ipynb : %.ipynb
	jupyter nbconvert --to notebook --execute --allow-errors $<

# %.tex : %.nbconvert.ipynb
# 	jupyter nbconvert --to latex $< --output $(basename $@)

%.pdf : %.nbconvert.ipynb
	jupyter nbconvert --to pdf --template report $< --output $(basename $@)

.PHONY: clean-ipynb
clean-ipynb:
	$(RM) *.ipynb

.PHONY: clean-pdf
clean-pdf:
	$(RM) *.pdf

# for debugging
print-%  : ; @echo $* = $($*)
