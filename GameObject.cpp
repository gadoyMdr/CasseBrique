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
