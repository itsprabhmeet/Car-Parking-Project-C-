fx_version 'cerulean'
game 'gta5'
lua54 'yes'
use_experimental_fxv2_oal 'yes'
author 'Your Name'
description 'Resource Description'
version '1.0.0'

client_scripts {
    'Modules/**/*.lua'
}

server_scripts {
    '@oxmysql/lib/MySQL.lua',
    'Modules/**/*.lua'
}

shared_scripts {
    '@ox_lib/init.lua',
    'Shared/**/*.lua'
}

ui_page 'Web/index.html'

files {
    'Web/index.html',
    'Web/style.css',
    'Web/script.js',
    'Web/Assets/**/*'
}