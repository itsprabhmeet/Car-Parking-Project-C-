-- Shared code between client and server
local ResourceName = GetCurrentResourceName()

-- Add your shared functions and constants here
Config = {}
Config.Debug = false

-- Example shared function
function Config.LogDebug(message)
    if Config.Debug then
        print(string.format('[%s] %s', ResourceName, message))
    end
end