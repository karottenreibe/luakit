---------------------------------------------------------
-- Bindings for the web inspector                      --
-- (C) 2010 Fabian Streitel <karottenreibe@gmail.com>  --
---------------------------------------------------------

print("foo")

-- Register signal handlers and enable inspector.
webview.init_funcs.inspector = function (view, w)
    view:set_prop("enable-developer-extras", true)
    view:add_signal("inspect-web-view", function ()
        return widget{type="webview"}
    end)
    view:add_signal("show-inspector", function (iview)
        -- TODO
    end)
end

-- Toggle web inspector.
webview.methods.toggle_inspector = function (view, w)
    if view.inspector.visible then
        view.inspector:close()
    else
        view.inspector:show()
    end
end

-- Add command to toggle inspector.
local cmd = lousy.bind.cmd
add_cmds({
    cmd({"inspect"},       function (w)    w:toggle_inspector() end),
})

