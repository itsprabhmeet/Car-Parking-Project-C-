-- Server-side code
local ResourceName = GetCurrentResourceName()

-- Initialize server-side resource
AddEventHandler('onResourceStart', function(resourceName)
    if resourceName ~= ResourceName then return end
    
    -- Your initialization code here
end)

-- Example event handler
RegisterNetEvent(ResourceName..':exampleEvent')
AddEventHandler(ResourceName..':exampleEvent', function(data)
    -- Handle event
end)