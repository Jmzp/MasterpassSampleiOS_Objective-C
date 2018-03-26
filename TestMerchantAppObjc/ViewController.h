//
//  ViewController.h
//  TestMerchantAppObjc
//
//  Created by Jorge Zapata on 23/03/18.
//  Copyright © 2018 Jorge Zapata. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MCCMerchant/MCCCheckoutRequest.h>
#import <MCCMerchant/MCCCheckoutResponse.h>
#import <MCCMerchant/MCCMasterpassButton.h>
#import <MCCMerchant/MCCMerchantDelegate.h>

// La clase ViewController adoptara el protocolo MCCMerchantDelegate
@interface ViewController : UIViewController <MCCMerchantDelegate>


- (void)didFinishCheckout:(MCCCheckoutResponse * _Nonnull)checkoutResponse;
- (void)didGetCheckoutRequest:(nullable BOOL (^)(MCCCheckoutRequest * _Nonnull))completionBlock;
- (void)didReceiveCheckoutError:(NSError * _Nonnull)error;
- (MCCMasterpassButton * _Nullable)getMasterPassButton;

@end

