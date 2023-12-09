#NewTex#
NewTex is a CLI for creating LaTex files from templates

##Usage##
The 'newtex' command in your terminal to create a new LaTex document in that folder.

Two areguments can be passed to the command. The first is the filename of the new LaTex
document you wish to create. The second argument is the name of the template you want to
use to create the file. These templates are .tex files stored in the /templates directory.
The template can be selected by passing the name of the template file without the tex.

The default template is assignment.tex and and the default file name is document.tex.

##Installation##
This version is for use with Linux. To install NewTex download this repository.
Run the following
'''
make
sudo make install
'''
To run on windows you can compile newtex.c without
'''
gcc newtex.c -n newtex.exe
'''
where you wish the program to be installed.
You will then need to add newtex.exe to your PATH to ensure that newtex is available
from the folders where you wish to use the CLI.


