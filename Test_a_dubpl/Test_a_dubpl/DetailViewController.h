//
//  DetailViewController.h
//  Test_a_dubpl
//
//  Created by DING FENG on 8/26/16.
//  Copyright © 2016 upyun.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end

