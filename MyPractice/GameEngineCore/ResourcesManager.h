#pragma once

// Ό³Έν :
class ResourcesManager
{
public:
	// constructer destructer
	ResourcesManager();
	~ResourcesManager();

	// delete Function
	ResourcesManager(const ResourcesManager& _Other) = delete;
	ResourcesManager(ResourcesManager&& _Other) noexcept = delete;
	ResourcesManager& operator = (const ResourcesManager& _Other) = delete;
	ResourcesManager& operator = (ResourcesManager&& _Other) noexcept = delete;

protected:

private:

};

