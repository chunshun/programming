vim
- word definition:
    word:the lowercase commands define a *word* as a continuous sequence of underscores,letters,and digits.The uppercase commands define a *word* as a contiguous sequence of nonwhitespace characters 

general mode:
- `w` or `W`:forward a word
- `b` or `B`:backward a word
- `e` or `E`: end of word
  
- lines
    - `0` or `$`: end or start of the line
    - `^`:first non-blank position of the line
    - `+` ,`-`:the next or the last non-blank position of the line
    - `Enter`:first blank character of next line
    - `n |`:jump to the *n* column of line 
    - `n H`:*n* of lines after top line
    - `n L`:*n* lines before last line
- scrolling
    - `ctrl F`,`ctrl B`:scroll forward,scroll backward one screen
    - `ctrl D`,`ctrl U`:scroll down ,up one-half screen
    - `z Enter`:position current cursor line to the top
    - `z .`:reposition line with cursor: to top of screen
    - `ctrl E`,`ctrl Y`:line scroll up and down
- line number
    - `ctrl G`:display current line number
    - `n G`:move to the line number of *n*
    - `G`: to the end line of file
- cursor marking
    - `m x`:mark current cursor position as *x*
    - `' x`:put the cursor to the position `x`(x has been marked)
    - `' '`:return to previous mark position(given to marked position)
    - `` x`:move to beginning of lien containing previous mask
- editing commands
    - `i`,`a`:insert text before,after cursor
    - x