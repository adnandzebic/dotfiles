" Vundle plugin manager requirements
set nocompatible              " be iMproved, required
filetype off                  " required

" Colorscheme
colorscheme gruvbox
set background=dark

" hide tilde sign on blank lines
autocmd Colorscheme * highlight EndOfBuffer ctermbg=black ctermfg=black

" hide tilde sign on blank lines
autocmd Colorscheme * highlight VertSplit ctermbg=black

" Use vim-devicons in startify
function! StartifyEntryFormat()
	return 'WebDevIconsGetFileTypeSymbol(absolute_path) ." ". entry_path'
endfunction

" Gruvbox setup
if g:colors_name == 'gruvbox'
	" Normal text
	autocmd Colorscheme * highlight Normal ctermbg=none

	" Remove background color from sign column
	autocmd Colorscheme * highlight SignColumn ctermbg=none

	" Improve color of warnings
	autocmd Colorscheme * highlight CocWarningSign ctermfg=yellow ctermbg=none

	" Improve color of variables
	autocmd Colorscheme * highlight def link LspCxxHlSymVariable Macro

	" Improve color of highlighted text
	autocmd Colorscheme * highlight Visual cterm=bold ctermbg=DarkGrey ctermfg=NONE
endif

" use longer separator │ (U+2502) by default instead of | (U+007C)
set fillchars+=vert:│

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'	" let Vundle manage Vundle, required
Plugin 'majutsushi/tagbar'
Plugin 'scrooloose/nerdtree'
" Plugin 'Xuyuanp/nerdtree-git-plugin'
" Plugin 'lambdalisue/fern.vim'
" Plugin 'ludovicchabant/vim-gutentags'
Plugin 'tpope/vim-surround'
Plugin 'tpope/vim-commentary'
Plugin 'tpope/vim-fugitive'
Plugin 'tpope/vim-dispatch'
Plugin 'junegunn/fzf'
Plugin 'junegunn/fzf.vim'
Plugin 'ryanoasis/vim-devicons'
Plugin 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'
Plugin 'neoclide/coc.nvim'
Plugin 'jackguo380/vim-lsp-cxx-highlight'
Plugin 'mhinz/vim-startify'
" Plugin 'glepnir/spaceline.vim'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
" Plugin 'edkolev/tmuxline.vim'
" Plugin 'octol/vim-cpp-enhanced-highlight'
" Plugin 'sheerun/vim-polyglot'
" Plugin 'jeaye/color_coded'
" Plugin 'jaxbot/semantic-highlight.vim'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

" No line wrapping
set nowrap

" Configure tab as 4 spaces
set tabstop=4
set shiftwidth=4

" Finding files
set path+=**

" Display all matching files when we tab complete
set wildmenu

" use , as leader key
let mapleader = ","

" Map jk to escape in insert mode
inoremap jk <Esc>

" Map ; to : in normal mode
nnoremap ; :

" Use ,d to toggle nerdtree
map <silent> <leader>d :NERDTreeToggle<CR>

" Close nerdtree after opening a file
let NERDTreeQuitOnOpen = 1

" Show hidden files and folders
let NERDTreeShowHidden = 1

" Hide 'press ? for help' in nerdtree
let NERDTreeMinimalUI = 1

" Hide DIR arrows
let NERDTreeDirArrowExpandable = ''
let NERDTreeDirArrowCollapsible = ''

" Use ,t to toggle tagbar
map <silent> <leader>t :TagbarToggle<CR>

" Open tagbar automatically for C and Python files
" autocmd FileType c,python TagbarOpen

" Hide help menu at the top of tagbar
let g:tagbar_compact = 1

" Use ,f to to search
map <leader>f :Ag 

" Enable cursor line
set cursorline

" Enable mouse scrolling and mouse selection
set mouse=a

" Automatic closing brackets for vim (disabled in favor of endwise plugin)
" inoremap " ""<left>
" inoremap ' ''<left>
" inoremap ( ()<left>
" inoremap [ []<left>
" inoremap { {}<left>
" inoremap {<CR> {<CR>}<ESC>O
" inoremap {;<CR> {<CR>};<ESC>O

" Tag jumping
command! MakeTags !ctags -R .

" Snippets
nnoremap ,gwt :-1read $HOME/.vim/.skeleton.c<CR>3ji
set rtp+=~/.vim/my-snippets

" Show line numbers
set number

" Use relative line numbers
" set relativenumber
" set rnu
"
" Airline
let g:airline_powerline_fonts = 1

if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif

" unicode symbols
let g:airline_left_sep = '»'
let g:airline_left_sep = '▶'
let g:airline_right_sep = '«'
let g:airline_right_sep = '◀'
let g:airline_symbols.linenr = '␊'
let g:airline_symbols.linenr = '␤'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.branch = '⎇'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.paste = '∥'
let g:airline_symbols.whitespace = 'Ξ'

" airline symbols
let g:airline_left_sep = ''
let g:airline_left_alt_sep = ''
let g:airline_right_sep = ''
let g:airline_right_alt_sep = ''
let g:airline_symbols.branch = ''
let g:airline_symbols.readonly = ''
let g:airline_symbols.linenr = ''

let g:airline_theme = 'base16'

let s:hidden_all = 0
function! ToggleHiddenAll()
	if s:hidden_all  == 0
		let s:hidden_all = 1
		set noshowmode
		set noruler
		set laststatus=0
		set noshowcmd
		set nonumber
	else
		let s:hidden_all = 0
		set showmode
		set ruler
		set laststatus=2
		set showcmd
		set number
	endif
endfunction

" Use ,h to toggle hide all
map <silent> <leader>h :call ToggleHiddenAll()<CR>

" autocmd BufReadPost * call ToggleHiddenAll()
autocmd VimEnter * call ToggleHiddenAll()

" no folding for diffs
if &diff
	set diffopt=filler,context:1000
	" set background=light
endif

command! -bang -nargs=* GGrep
  \ call fzf#vim#grep(
  \   'git grep --line-number -- '.shellescape(<q-args>), 0,
  \   fzf#vim#with_preview({'dir': systemlist('git rev-parse --show-toplevel')[0]}), <bang>0)
