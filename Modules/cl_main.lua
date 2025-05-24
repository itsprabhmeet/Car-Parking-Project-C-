-- Client-side code
local ResourceName = GetCurrentResourceName()

-- Initialize client-side resource
AddEventHandler('onClientResourceStart', function(resourceName)
    if resourceName ~= ResourceName then return end
    
    -- Your initialization code here
end)

-- Example event handler
RegisterNetEvent(ResourceName..':exampleEvent')
AddEventHandler(ResourceName..':exampleEvent', function(data)
    -- Handle event
end)