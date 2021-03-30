#include "GameObject.h"

using namespace std;

GameObject::GameObject() : MonoBehavior() {
    name = "Empty";
    tag = Tag::None;
}

GameObject::GameObject(const std::string& _name) : MonoBehavior() {
    name = _name;
    tag = Tag::None;
}

GameObject::GameObject(const std::string& _name, Tag _tag) : GameObject(_name) {
    tag = _tag;
}

void GameObject::Update(){}

void GameObject::MoveChildren(sf::Vector2f dir) {
    for (GameObject* go : children) {
        go->OnTriggerChildrenUpdate();
    }
}

void GameObject::MakeChildOf(GameObject* go) {
    children.push_back(go);
}

void GameObject::Free(GameObject* go) {
    children.erase(std::remove(children.begin(), children.end(), go), children.end());
}

void GameObject::OnTriggerChildrenUpdate() {}
