# Reactive Library

A library of reactive properties and collections for standard data types in Unreal Engine 5.

![License](https://img.shields.io/badge/license-MIT-blue) ![Version](https://img.shields.io/badge/version-1.0.0-green) ![UE5](https://img.shields.io/badge/Unreal%20Engine-5.3+-blue?logo=unrealengine)

## 🚀 Features

### **Reactive Property**
**Purpose:**  
Encapsulates the functionality for working with a field of a specific type within a UObject.
- The field (value or pointer) is made private.
- Public getter `GetValue` and setter `SetValue` methods are added.
- A public delegate `OnValueChanged` is added for external tracking of changes to the private field (via `SetValue`).

### **Reactive Collection**
**Purpose:**  
Encapsulates the functionality for working with a collection field (`TArray`) within a UObject.
- The collection field (TArray, where element is value or pointer) is made private.
- Public getter `GetCollection` and setter `SetCollection` methods are added.
- A public delegate `OnCollectionChanged` is added for external tracking of changes to the private collection (via `SetCollection`).
- Additional public methods for working with collection elements.
- A public delegate `OnElementReplaced` is added for external tracking of changes to the value of a collection element via methods (e.g., `TrySetValueByIndex`).
