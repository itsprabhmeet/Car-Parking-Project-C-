#include <crow.h> 
#include <iostream>
#include<string>
#include<unordered_map>

using namespace.std;

// Your existing parking slot classes go here...

unordered_map<int, RegularSlot> regularSlots;
unordered_map<int, PremiumSlot> premiumSlots;

void initializeSlots() 
{
    for (int i=1;i<=10; ++i)
    {
        regularSlots[i] = RegularSlot();
    }
    for (int i=1; i<=5; ++1)
    {
        premiumSlots[i] = PremiumSlot();
    }
}

int main()
{
    initializeSlots();
    crow::SimpleApp app;
    CROW_ROUTE(app, "/park").methods("POST"_method)([](const crow::request& req)
    {
        auto json = crow::json::load(req.body);
        if (!json)
        {
            return crow::response(400, "Invalid JSON");
        }
        string carNumber = json["carNumber"].s();
        string parkingType = json["parkingType"].s();
        int slotNumber = json["slotNumber"].i();

        if (parkingType == "regular" &&  slotNumber >= 1 && slotNumber <= 10)
        {
            regularSlots[slotNumber].parkCar(carNumber);
            return crow::response(200, "car parked in regular slot.");
        }
        else if (parkingType == "premium" && slotNumber >=1 && slotNumber <= 5)
        {
            premiumSlots[slotNumber].parkCar(carNumber);
            return crow::response(200, "car parked in premium slot.");
        }
        else 
        {
            return crow::response(400, "Invalid parking type or Slot Number");
        }
    });

    CROW_ROUTE(app, "/vacant").methods("POST"_method)([](const crow::response& req)
    {
        auto json = crow::json::load[req.body];
        if (!json)
        {
            return crow::response(400, "Invalid JSON");
        }

        string carNumber = json["carNumber"].s();
        string parkingType = json["parkingType"].s();
        int slotNumber = json["slotNumber"].i();

        if (parkingType == "regular" && slotNumber >= 1 && slotNumber <= 10)
        {
            if (regularSlots[slotNumber].getParkedCar()== carNumber)
            {
                regularSlots[slotNumber].vacateSlot();
                return crow:response(200, "Regular slot vacanted");
            }
            else 
            {
                return crow:response(400, "No car found in the slot");
            }
        }
        if (parkingType == "premium" && slotNumber >= 1 && slotNumber <= 5)
        {
            if (premiumSlots[slotNumber].getParkedCar()== carNumber)
            {
                premiumSlots[slotNumber].vacateSlot();
                return crow:response(200, "Premium slot vacanted");
            }
            else 
            {
                return crow:response(400, "No car found in the slot");
            }
        }
    });

    app.port(8080).multithreaded().run();
    return 0;
    
}