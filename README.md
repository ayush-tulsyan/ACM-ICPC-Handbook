ACM-ICPC Handbook
=================

This is a repository for the upcoming ACM-ICPC onsite contests of Asia West Subcontinent sites.
It currently hosts the team notebook.
This repository contains code from the stanford's repository for their ACM-ICPC teams. It can be visited at [this](https://github.com/jaehyunp/stanfordacm) link.

Generating team notebook
========================
The included Python scripts can generate the notebook in PDF or HTML format. Both scripts read the contents of the notebook from `contents.txt`.

PDF version
-----------
Requires: [Python 2/3](https://www.python.org/), [latexmk](https://www.ctan.org/pkg/latexmk/)

Script for generating the PDF file is `generate_pdf.py`. The script requires latexmk package.
The LaTeX template that the script uses is `notebook.tex`. It recognizes common file extensions for C/C++/Java/Python and applies syntax highlighting. In order to change the color scheme or add additional languages, both `notebook.tex` and `generate_pdf.py` should be modified accordingly.

HTML version
------------
Requires: [Python 2/3](https://www.python.org/), [enscript](https://www.gnu.org/software/enscript/)

Script for generating the HTML file is `generate_html.py`.
Syntax highlighting is handled solely by enscript, and in order to change the color schemes, either the default options of enscript or `generate_html.py` should be edited accordingly.
