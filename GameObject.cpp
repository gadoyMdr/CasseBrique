#include "GameObject.h"

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

void GameObject::Update(){
    /*for (GameObject* go : children) {
        go->OnTriggerChildrenUpdate();
    }*/
}

void GameObject::MakeChildOf(GameObject* go) {
    go->children.push_back(this);
    parent = go;
}

void GameObject::Free() {
    parent->children.erase(std::remove(parent->children.begin(), parent->children.end(), this), parent->children.end());
    parent = nullptr;
}

void GameObject::OnTriggerChildrenUpdate() {}
