all: format readme notebook docker
readme:
	python3 scripts/gen-readme.py > README.md

format:
	python3 scripts/format/format-algorithms.py --path ${CURDIR}/algorithms

notebook: format
	python3 scripts/notebook/gen.py \
		--path ${CURDIR}/algorithms \
		--confpath ${CURDIR}/settings-and-macros \
		--teamname "${team_name}"

notepdf:
	pdflatex -interaction=nonstopmode -halt-on-error ${CURDIR}/scripts/notebook/notebook.tex 

docker:
	python3 scripts/docker/cleanup.py
