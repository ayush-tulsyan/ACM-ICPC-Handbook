ACM-ICPC Handbook
=================

This repository hosts a 25 page notebook which acts as reference material for ACM-ICPC onsite contests
We have borrowed code from the stanford's repository for their ACM-ICPC teams. It can be visited at [this](https://github.com/jaehyunp/stanfordacm) link.

Generating team notebook
========================
The included Python scripts can generate the notebook in PDF format. Script reads the contents of the notebook from `contents.txt`.

PDF version
-----------
Requires: [Python 2/3](https://www.python.org/), [latexmk](https://www.ctan.org/pkg/latexmk/)

Script for generating the PDF file is `generate_pdf.py`. The script requires latexmk package.
The LaTeX template that the script uses is `notebook.tex`. It recognizes common file extensions for C/C++/Java/Python and applies syntax highlighting. In order to change the color scheme or add additional languages, both `notebook.tex` and `generate_pdf.py` should be modified accordingly.
