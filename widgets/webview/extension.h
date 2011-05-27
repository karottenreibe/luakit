/*
 * widgets/webview/extension.h - webview extension framework header
 *
 * Copyright © 2010-2011 Mason Larobina <mason.larobina@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LUAKIT_WIDGET_H
#define LUAKIT_WIDGET_H

#include "widgets/webview.h"

/**
 * Returned by the \ref index and \ref noindex functions of an extension if
 * nothing was matched.
 */
#define WEBVIEW_EXTENSION_NO_MATCH -1

/** Extension for the webview widget */
typedf struct {
    /**
     * Extension initialization function
     *
     * Called from the webview constructor.
     */
    void (*constructor)(webview_data_t *);
    /**
     * Extension destruction function
     *
     * Called from the webview destructor.
     */
    void (*destructor)(webview_data_t *);
    /**
     * Extension for luaH_webview_index
     *
     * @return WEBVIEW_EXTENSION_NO_MATCH if it didn't match and the number of
     *         pushed arguments otherwise.
     */
    int (*index)(lua_State* L, webview_data_t *, luakit_token_t *);
    /**
     * Extension for luaH_webview_newindex
     *
     * @return WEBVIEW_EXTENSION_NO_MATCH if it didn't match and the number of
     *         pushed arguments otherwise.
     */
    int (*newindex)(lua_State* L, webview_data_t *, luakit_token_t *);
} webview_extension_t;

#endif

// vim: ft=c:et:sw=4:ts=8:sts=4:tw=80
