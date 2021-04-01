#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject() : MonoBehavior() {
    name = "Empty";
    tag = Tag::None;
    parent = nullptr;
}

GameObject::GameObject(const std::string& _name) : MonoBehavior() {
    name = _name;
    tag = Tag::None;
    parent = nullptr;
}

GameObject::GameObject(const std::string& _name, Tag _tag) : GameObject(_name) {
    tag = _tag;
}

std::vector<GameObject*> GameObject::GetChildren() {
    return children;
}

void GameObject::Update(){
    for (GameObject* go : children) {
        go->OnTriggerChildrenUpdate();
    }
}

void GameObject::MakeChildOf(GameObject* go) {
    if (std::count(go->children.begin(), go->children.end(), this)) return;

    std::cout << "lol" << std::endl;
    
    go->children.push_back(this);
    parent = go;

    OnMadeChildOf(go);
}

void GameObject::Free() {
    if (parent == nullptr) return;

    parent->children.erase(std::remove(parent->children.begin(), parent->children.end(), this), parent->children.end());
    parent = nullptr;
}

void GameObject::OnMadeChildOf(GameObject* other){}

void GameObject::OnTriggerChildrenUpdate() {}

void GameObject::Destroy() {
    Free();
    MonoBehavior::Destroy();
}
