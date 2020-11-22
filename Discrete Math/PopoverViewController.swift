//
//  PopoverViewController.swift
//  Discrete Math
//
//  Created by Jody Kocis on 3/2/19.
//  Copyright © 2019 Joseph Kocis. All rights reserved.
//

import Foundation
import UIKit

class PopoverViewController: UIViewController {
    
    let defaults = UserDefaults.standard
    
    @IBOutlet weak var textField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        textField.isUserInteractionEnabled = false
    }
    
    @IBAction func variableTextInput(_ sender: Any) {
        if let button = sender as? UIButton {
            textField.text?.append(button.titleLabel?.text ?? "")
        }
        
    }
    
    @IBAction func backspace(_ sender: Any) {
        if let text = textField.text {
            if (text.endIndex == text.startIndex) {
                return
            }
            let index = text.index(before: text.endIndex)
            textField.text?.remove(at: index)
        }
    }
    
    @IBAction func createEquation(_ sender: Any) {
        
        if let text = textField.text {
            addEquation(equation: text)
        }
        self.dismiss(animated: true, completion: nil)
    }
    
    // Adding an equation
    func addEquation(equation: String) {
        var equations = defaults.object(forKey: equationsKey) as? [String] ?? [String]()
        equations.append(equation)
        defaults.set(equations, forKey: equationsKey)
        
        if let viewController = presentingViewController?.children[0].children[0] as? MasterViewController {
            viewController.numEquations = viewController.getEquations().count
            viewController.tableView.reloadData()
        }
    }
    
}
