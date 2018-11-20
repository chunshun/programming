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
    - `n G`:move to the line numbe``r of *n*
    - `G`: to the end line of file
- cursor marking
    - `m x`:mark current cursor position as *x*
    - `' x`:put the cursor to the position `x`(x has been marked)
    - `' '`:return to previous mark position(given to marked position)
    - `` x`:move to beginning of lien containing previous mask
- editing commands
    - `i`,`a`:insert text before,after cursor
    - x
- visual mode
    - `v`,`V`,`ctrl v`:visual mode,visual line mode,visual block mode

- editing commands
    - insert
        - `I`,`A`:inset text before,after cursor
        - `o`,`O`:open new line for text below,above cursor 
    - change
        - `c w`:change word
        - `c c`:change current line
        - `C`:change to end of line
        - `r`:replace single character
        - `R`:type over(overwrite) characters
        - `s`:substitute : delete character and insert new text
        - `S`:substitute : delete current line and insert new text
    - delete,move
        - `x`:delete character under cursor
        - `X`: delete character before cursor
        - `dw`:delete word
        - `dd`:delete line 
        - `D`:delete from the cursor to the end of line 
        - `p`,`P`:put deleted text after,before cursor
        - `" n p`:put text from buffer number *n* after cursor(for last nine deletions)
        - `db`:delete word backward 
        - `dk`:delete line backward
        - 
    - yank
        - `y w`:yank(copy) word 
        - `y y`:copy line 
        - `p,P`:put yanked text after,before cursor

    - other commands
        - `.`:repeat last edit command
        - `u`,`U `:undo last edit;restore current line
        - `J`:join two lines
- Exit commands
    - `:w`:write(save) file
    - `w!`:write(save) file,overriding protection
    - `:x`:write(save) and quit file
    - `30,60w file-name`:write from line 30 through line 60 and saved to file
    - `30,60w >>file-name`:write line 30 through line 60 and append to the file
    - `e!`:return to version of current file as of time of last write
- input mode shortcuts
    - vim provides two ways to decrease the amount of typing you have to do:*abbreviation* and *map*
- the substitute command
    - `:[abbr1[,abbr2]]s/old/new/[flags]`
- window management
    - `ctrl w,s`:split the window
    - `ctrl w,n`:same as `:new` without a file argument
    - `ctrl w,c`:same as the `:close` command
- `shift`+`->`or`<-`:move forward or backward
- command mode
    - `ctrl a`:insert all names that match the pattern
    - `ctrl d`:list the name that match the pattern;for filenames,directories are highlighted
    - `ctrl n`:go to next multiple *wildchar* matches,if any; otherwise, recall more recent history line
    - `ctrl p`:go to previous of multiple *wildchar* matches,if any;otherwise,recall older history line
- tag commands
    - `: di `:display registers 


- multi-tasks   
    - jump to previous locations:
        - `ctrl o`(next),`ctrl i`(previous)
        - using a change list(:changes list the changes of file)
            - `g;`:go to the previous change
            - `g,`:to jump to the position of the next change
- `n |`:move the cursor to the *n* columns
- using masks, changes,jumps
- `ctrl+w`,`ctrl+w`:  visual mode,打开选中文件
```c
#include <stdio.h>
int main(){
    printf("hello world");
    
}
```
- `g,f`:normal mode,cover the cursor on the file-name, enter `g,f` to open the file
- `g,d`:go to the definition
  
`v`=>enter the visual mode=>select the file name to open=>`ctrl+w,ctrl+f`=>open the file 
- `:help command`:to open the help-doc
- `sp`,`vp`: to split the pane  vertical,to split the pane 

copy,paste,cut
`d,e`=>to delete one word behind
`d,w`=>to delete one word before



- essentials

`I`: jump to the end of line  and enter the insert mode
`A':jump to the beginning of the line and enter the insert mode

- move the code block
`v`:enter thre visual mode and select the code block,`>>`: move the code block (tab to right)


