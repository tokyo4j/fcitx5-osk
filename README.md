## Start

```
mkdir -p ~/.local/share/fcitx5/addon
cp osk.conf ~/.local/share/fcitx5/addon
FCITX_ADDON_DIRS=(pwd)/build:/usr/lib/fcitx5 fcitx5 '*=5'
```
