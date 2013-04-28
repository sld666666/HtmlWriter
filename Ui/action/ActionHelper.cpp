#include "ActionHelper.h"
#include "ServiceManager.h"

using namespace service;

namespace UiUtils{

	ActionHelper::ActionHelper()
	{

	}

	ActionHelper::~ActionHelper()
	{

	}

	vector<IAction*> ActionHelper::getActions(vector<long>ids)
	{
		vector<IAction*> actions(ids.size());
		transform(ids.begin(), ids.end(), actions.begin()
			, bind(&ActionHelper::getAction,_1));

		return actions;
	}

	IAction* ActionHelper::getAction(long id)
	{
		IService* foundService = ServiceManager::instance().find(id);
		return static_cast<IAction*>(foundService);
	}
}