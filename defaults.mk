%.ipynb : %.md
	notedown --match python $< > $@

%.nbconvert.ipynb : %.ipynb
	jupyter nbconvert --to notebook --execute --allow-errors $<

%.pdf : %.nbconvert.ipynb
	jupyter nbconvert --to pdf $< --output $(basename $@)

.PHONY: clean
clean:
	$(RM) *.ipynb
	$(RM) *.pdf

# for debugging
print-%  : ; @echo $* = $($*)
