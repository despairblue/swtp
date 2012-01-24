# Compiler
PDFLATEX=pdflatex
MAKEINDEX=makeglossaries

TEXFILE=Lastenheft

#PDFFLAGS=-interaction=nonstopmode


all: $(TEXFILE).pdf

.PHONY: clean cleanall all $(TEXFILE).pdf

$(TEXFILE).pdf: $(TEXFILE).tex
	# Initial run
	$(PDFLATEX) $(PDFFLAGS) $(TEXFILE).tex
	$(MAKEINDEX) $(TEXFILE)
	$(PDFLATEX) $(PDFFLAGS) $(TEXFILE).tex
	$(PDFLATEX) $(PDFFLAGS) $(TEXFILE).tex

Test.pdf: $(TEXFILE).tex
	$(PDFLATEX) $(PDFFLAGS) $(TEXFILE).tex
	makeindex -s $(TEXFILE).ist -t $(TEXFILE).alg -o $(TEXFILE).acr $(TEXFILE).acn
	makeindex -s $(TEXFILE).ist -t $(TEXFILE).glg -o $(TEXFILE).gls $(TEXFILE).glo
	makeindex -s $(TEXFILE).ist -t $(TEXFILE).slg -o $(TEXFILE).syi $(TEXFILE).syg
	$(PDFLATEX) $(PDFFLAGS) $(TEXFILE).tex
        
#house-keeping target
cleanall: clean
	rm -f *.pdf
	clear
        
clean:
	rm -f *.out *.toc *.aux *.idx *.ilg *.log *.ind *.acn *.acr *.alg *.glg *.glo *.gls *.ist *.xdy
	clear
