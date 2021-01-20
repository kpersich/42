find . -name "*.sh" -type f | rev | cut -d '/' -f 1 | rev | sed 's/.sh$//'
