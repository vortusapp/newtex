newtex: newtex.c
	gcc -o newtex newtex.c
	chmod +x newtex

CONFIG_DIR=$(HOME)/.config/newtex
TEMPLATES_DIR=$(CONFIG_DIR)/templates
FONTS_DIR=$(CONFIG_DIR)/fonts

# New target for installation
install:
	# Create directories
	mkdir -p $(TEMPLATES_DIR)
	mkdir -p $(FONTS_DIR)

	# Create a blank assignment.tex file
	touch $(TEMPLATES_DIR)/assignment.tex

	# Copy the executable to /usr/local/bin
	cp newtex /usr/local/bin/newtex

	# Set the executable permission for the binary
	chmod +x /usr/local/bin/newtex

.PHONY: install
