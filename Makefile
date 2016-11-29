SHELL := /bin/zsh

all: clean notebook.pdf
	rm notebook.aux notebook.toc notebook.log notebook.fls notebook.out contents.tex notebook.fdb_latexmk

notebook.pdf:
	python generate_pdf.py

clean:
	rm notebook.pdf
