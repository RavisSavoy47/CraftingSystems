# Crafting System

## Pickups
- They are inheried from interactables. Each pickup has an ID, name, and the action. The ID and the name is to find a certain item. The action for the pickup is what the item is used for.

## Inventory DataTable
- Is a list of pickups thta are in the world. Create what pickup your using and set the values for it. It has a thumbnail to have a visual display of what the pickup is. It has a description that can be changed for each different pickup. U can create a craft combinations from different pickups from the datatable.

## Widget Blueprint_Inventory
- The visual display of the inventory and has the crafting menu with it. To change what displays in the crafting recipes and the items required to craft. Get the item that u want to display from the datatable and select its row name for that item. For the items rquired to make said item use the items that are from the craft combinations and choose their row names and trheir values would set from that item.

## Controls 
- Use WASD to move the player 
- Use the mouse to controls the camera
- Use E to pick up items 
- Use TAB to open the inventory

