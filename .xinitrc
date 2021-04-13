#!/bin/sh
#
# ~/.xinitrc
#
# Executed by startx (run your window manager from here)
if [ -d /etc/X11/xinit/xinitrc.d ]; then
  for f in /etc/X11/xinit/xinitrc.d/*; do
    [ -x "$f" ] && . "$f"
  done
  unset f
fi

# Maps caps lock to control
if [ -s ~/.Xmodmap ]; then
    xmodmap ~/.Xmodmap
fi

# Start key bindings
exec sxhkd &


# Turn on MPD ("systemctl enable mpd.service" should work as well)
#mpd

# Set wallpaper
dwall -s island &

# Use flu.x
# xflux -z 94601

# Set cursor
xsetroot -cursor_name left_ptr &

# Run dunst
dunst &

# Hide cursor
#unclutter -noevents -idle 5 &

# fix java apps like matlab
# wmname LG3D &

# use unity settings daemon for now...
# unity-settings-daemon &
# gnome-shell &

# Launch DWM
# exec /home/adnan/scripts/dwm/dwm-start

# Use third monitor
.screenlayout/home-2-monitors.sh &

# Launch DWM's status bar
# exec /home/adnan/scripts/dwm/dwm-status.sh &
#dwmst & exec dwm
exec bspwm
#exec ratpoison
#exec startxfce4

