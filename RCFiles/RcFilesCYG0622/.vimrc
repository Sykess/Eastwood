
" My vimrc file.
"
" Maintainer:	Nathan Caron
" Last change:	2016 Mar 21
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"	    for OpenVMS:  sys$login:.vimrc


set nocompatible     " use vim settings rather than vi (must be first)
let mapleader = ","  " set which key acts as <leader>
set laststatus=2
set encoding=utf-8

" ####################### VUNDLE STUFF!!! #######################
"if v:version > 704
    filetype off
    set rtp+=~/.vim/bundle/Vundle.vim
    call vundle#begin()

    "Plugins go here:
    Plugin 'VundleVim/Vundle.vim'
    "Plugin 'Valloric/YouCompleteMe'
    Plugin 'supertab'
    Bundle 'jewes/Conque-Shell'
    Bundle 'Lokaltog/vim-powerline'
    let g:Powerline_symbols = 'unicode'

    call vundle#end()
    filetype plugin indent on
"endif

" ######################### END VUNDLE! #########################

" Uncomment following line to have gvim with black background
" highlight Normal guifg=white guibg=black


" ########################### My Sets ###########################

set backspace=indent,eol,start " allow backspacing over everything in insert mode
if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file
endif
if has('mouse')
    set mouse=a         " enable mouse
endif
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set showmode            
set incsearch		" do incremental searching
set hlsearch            " turn on highlight searching
set smartcase           " parse cases smartly while searching
set ignorecase          " case insensitive (set noignorecase to turn off)
"set number             " show line numbers
"set numberwidth=10     " set number width for uniformity
syntax on               " can also use syntax enable
let g:load_doxygen_syntax=1
"set textwidth=0        " turn off physical line wrapping
"set wildmenu           " escape mode command autocompletion
"set wildmenu=list:longest
"set relativenumber     " like number but relative to cursor
"set cursorline         " makes a line across screen at cursor
"set hidden             " dont know
"set viusalbell         " dont know
set tabstop=8 
set softtabstop=0 
set expandtab           " expand tabs to spaces 
set shiftwidth=4        " spaces per level of indentation
set smarttab
set autoindent
set smartindent
set fileformats=unix,dos
:highlight Search ctermbg=yellow ctermfg=black " set highlight colors
"colorscheme shine
"set background=dark
"set background=light
"set t_Co=256          " set to 256 colors, should already be this way
"set lines=45 columns=151

" ######################### End of Sets #########################



" ######################### My autocmds #########################

" Only do this part when compiled with support for autocommands.
if has("autocmd")
  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
      " removes all autocommands for current group
      au!

      " For all text files set 'textwidth' to 78 characters.
      autocmd FileType text setlocal textwidth=78

      " When editing a file, always jump to the last known cursor position.
      " Don't do it when the position is invalid or when inside an event handler
      autocmd BufReadPost *
        \ if line("'\"") > 1 && line("'\"") <= line("$") |
        \   exe "normal! g`\"" |
        \ endif

  augroup END
else
  set autoindent		" always set autoindenting on
endif " has("autocmd")

" Set Bd to delete current buffer without deleting window
command! Bd bp|bd #

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r # | 0d_ | diffthis
		  \ | wincmd p | diffthis
endif

" ######################### End autocmd #########################





" ######################### My Mappings #########################

" Map jk to exit insert mode into normal mode:
inoremap jk <esc>
" Don't use Ex mode, use Q for formatting
map Q gq
" CTRL-U in insert mode deletes a lot.  Use CTRL-G u to first break undo,
" so that you can undo CTRL-U after inserting a line break.
inoremap <C-U> <C-G>u<C-U>
" Clear all searches
nnoremap <silent> <leader><space> :nohlsearch<cr>|
"inoremap <esc> <nop>  "can disable escape in insert mode
" Rotate windows (for use with split screens): (eg Rotate Left)
nnoremap <leader>rl <c-w>H
nnoremap <leader>rr <c-w>L
nnoremap <leader>rd <c-w>J
nnoremap <leader>ru <c-w>K
" Rotate all open windows (Rotate All)
nnoremap <leader>ra <c-w>r
" Set all windows equal size: (like == so ee)
nnoremap <leader>ee <c-w>=
" Enlarge Height and Enlarge Width:
nnoremap <leader>eh <c-w>+
nnoremap <leader>ew <c-w>>
" Fill Vertically(Top-bottom), and fill Side-side (horizon) and both (Fill)
nnoremap <leader>et <c-w>_
nnoremap <leader>es <c-w>\|
nnoremap <leader>ef <c-w>\|<c-w>_
" Switch windows (normal c-w-w)
nnoremap <leader>w <c-w><c-w>
" Map it to fix paragraphs that are huge 1 liners to separate lines
nnoremap <leader>q gqip
" Open vimrc in split screen to easily make changes:
nnoremap <leader>ev :vsplit $MYVIMRC<cr>
" Source vimrc so you can use changes without having to reload:
nnoremap <leader>sv :source $MYVIMRC<cr>
" Add semicolon to end of current line(useful for c++)
nnoremap <leader>; mqA;<esc>`q
" Set the Header with # signs I made:
nnoremap <leader>3 o<esc>99i#<esc>o###<esc>39a <esc>iSAMPLE TEXT HERE!<esc>39a <esc>i###<esc>o<esc>99i#<esc>o<esc>42i <esc>iSAMPLE TEXT HERE!<esc>kk16h
" Set Function Heaing with # I made:
nnoremap <leader>4 80i#<esc>o# Name:<esc>34a <esc>i#<cr># Description:<esc>27a <esc>i#<cr># Usage:<esc>33a <esc>i#<cr># Created:<esc>31a <esc>i#<cr><esc>80i#<esc>4k24h
" Add cpp style header doxygen style:
nnoremap <leader>ah o/<esc>115a*<esc>a//**<esc>o<esc>i*<cr><cr><cr><esc>118i*<esc>A/<esc>ka Description:<esc>
" Open bash in a new split window via ConqueTerm:
nnoremap <leader>ns :ConqueTermSplit bash<cr>
" User <leader> c and v to copy and paste using dummy file (a appends)
vnoremap <leader>c :w! ~/Documents/dummy.file<cr>
vnoremap <leader>a :w! >> ~/Documents/dummy.file<cr>
nnoremap <leader>v :r ~/Documents/dummy.file<cr>
" Make control-c copy to clipboard
vnoremap <c-c> "+y
" Make control-V in normal paste from clipboard
nnoremap <c-V> "+p
" Make \ go to start of sentence (previously 0)
nnoremap \ 0
" And hold shift and hit \ to go to end:
nnoremap \| $
" Call function to get line with max characters
nnoremap <leader>ml :call myfunctions#MaxLine()<cr>

nnoremap <leader><leader> <<

" ######################### End of maps #########################



" ######################### Misc stuffs #########################

" To replace all ^M in file from windows:
"    :%s/^V^M//g    "NOTE: ^V^M means type <c-V><c-M>
"
"
"
" To highlight everyhing after # columns: (80 in this case)
" /\%>80v.\+
" Also similar stuff:
" :match ErrorMsg '\%>80v.\+'     " aggressive red (:match to clear)
" :2mat ErrorMsg '\%81v.'         " less aggressive (highlights char 81) 
"
"
"
" "ap will print register a (@a)
"
"
"
" Convoluted way of doing the MaxLine functionality(but it works!):
"       NOTE: <c-r> means control-r, then ", then return
" :%s/./a/g        "Replace everything with 'a's
" :sort!           "Sort by column length
" ggy$             "Go to first line (longest) and copy it
" u                "Undo the sorting
" /<c-r>"<cr>      "Search for the longest line
" mm               "Mark it 'm'
" u                "Undo the replace
" 'm               "Go to the mark - there!
" ######################### End of misc #########################


