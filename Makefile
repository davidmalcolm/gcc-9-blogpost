all: blog.html

clean:
	rm *.html

SRC_FILES=*.c *.cc

blog.html: blog.html.in $(SRC_FILES) make-blog.py *.sh Makefile
	python ./make-blog.py $< > $@
