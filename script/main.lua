

--Da Brooo

Yu = {
	
	

}






-- the player stuff!!!
Player = {
	x = 468,
	y = 703,
	is_on_ship = false,

	Render = function(self)
		if self.is_on_ship == false then
			spr(20, 15, 6)
		end
	end,
	--updaing the player code!!!
	Update = function(self)
		local dx, dy = self.Move(self)
		self.HopInShip(self,dx, dy)
	end,

	--hop on in some ship!!!
	HopInShip = function(self, dx, dy)
		local index = get_map(self.x + dx * 2, self.y + dy * 2)
		print(index)
		if index == 79 then
			self.is_on_ship = true
			self.x = self.x + dx * 2
			self.y = self.y + dy * 2
		end
	end,



	--is collide
	Is_Collide = function(self, x, y, px, py)
		local index = get_map(x+px, y+py)

		local non_collideable_tiles = {18, 37}

		local is_collide = true
		for _index, value in ipairs(non_collideable_tiles) do
			if index == value then
				is_collide = false
				break
			end
		end

		return is_collide
	end,

	--the move code!!!
	Move = function(self)
		local direction = key()
		local dx, dy = 0, 0
		if direction == 1 then dy = - 1 end
		if direction == 2 then dx = -1 end
		if direction == 3 then dy = 1 end
		if direction == 4 then dx = 1 end

		local is_collide = self.Is_Collide(self, self.x, self.y, dx, dy)
		
		if is_collide == false then
			self.x = self.x + dx
			self.y = self.y + dy
		end
		return dx, dy
	end
}


--Mine ship!!!
Ship = {



}


--the Day timer stuff!!
Timer = {
	value = 0,

	--the update code
	Update = function(self)
		self.value = self.value + 0.1
	end,
	--the whole render code
	Render = function(self)
		local time_to_bar = math.floor((self.value/100 ) * 10)
		for i=0, time_to_bar do
			if i==time_to_bar then
				spr(i, 1, 115)
			else
				spr(i, 1, 113)
			end
		end
	end
}

--the Map stuff!!!
Map = {	
	Render = function(self, x, y)
		map(x - 20, y - 15, 40, 40, 0, 0)
	end
}


--##############################################################################################################################
--ALL DA IMPORTANT STUFFIEE!!!!
--##############################################################################################################################

function TIC()
	Update()
	Render()
end

function Update()
	Player.Update(Player)
	Timer.Update(Timer)
end

function Render()
	Map.Render(Map, Player.x, Player.y)
	Player.Render(Player)
	Timer.Render(Timer)
end
